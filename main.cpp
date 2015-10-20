#include <iostream>
#include <string>
#include <array>
#include <vector>

// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV
class JobRecord
{
public:
    JobRecord(int startYear, int endYear, std::string jobTitle, std::string companyName):
     mStartYear{startYear}
    , mEndYear{endYear}
    , mJobTitle{jobTitle}
    , mCompanyName{companyName}
    {}

    bool isValid() const
    {
        return !mCompanyName.empty()
                &&((mStartYear>1960)&&(mEndYear>1960))
                && (mJobTitle=="developer" || mJobTitle=="junior developer" || mJobTitle=="senior software developer");
    }

    void print() const
        {
            if (isValid())
                std::cout << "(" << mStartYear << " - " << mEndYear << ")"
                << std::endl << "Title: " << mJobTitle
                << std::endl << "Name of the Company: " << mCompanyName
                << std::endl << std::endl;
        }
private:
    int mStartYear;
    int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;

};

class CV
{
public:
    CV(const std::string &name, int birthYear, const std::string &skills, std::vector<JobRecord> &previousJobs) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
      , mPreviousJobs{previousJobs}
    {

    }
    CV(const std::string &name, int birthYear, const std::string &skills) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
    {

    }

    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1970) && (mBirthYear < 1995))
                && !mSkills.empty()
                && !mPreviousJobs.empty();
    }

    void print() const
    {
        if (isValid())
        {
            std::cout << mName << " (" << mBirthYear << ")" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Skills: " << mSkills << std::endl;
            std::cout << "Previous work record: " << std::endl;
            for (const auto& jr : mPreviousJobs)
                    {
                        if (jr.isValid())
                        {
                            jr.print();
                        }

                    }
            std::cout << std::endl;
        }
    }
    void addJobRecord(JobRecord jr)
        {
            mPreviousJobs.push_back(jr);
        }

private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    std::vector<JobRecord> mPreviousJobs;
};




int main()
{
    CV johnsCV{ "John Jonson", 1978,"C++, Java" };
        JobRecord johnsJR1{ 1996,2002,"senior","Microsoft" };
        JobRecord johnsJR2{ 1990,1995,"junior","IBM" };
        johnsCV.addJobRecord(johnsJR1);
        johnsCV.addJobRecord(johnsJR2);

        CV dansCV("Dan Davidson", 1988, "C++, Java"/*, "IBM 1996-1997"*/);
        JobRecord dansJR1{ 1996,1997,"developer","IBM" };
        dansCV.addJobRecord(dansJR1);

        CV willsCV{ "Will Walker", 1971, "C++, Java"/*, "IBM 1990-1999; Microsoft 1999-2010" */};
        JobRecord willsJR1{ 1990, 1999, "junior developer", "IBM" };
        JobRecord willsJR2{ 1999, 2010, "senior software developer", "Microsoft" };
        willsCV.addJobRecord(willsJR1);
        willsCV.addJobRecord(willsJR2);

        std::vector<CV> cvList{ johnsCV, dansCV, willsCV };

        for (const auto& cv : cvList)
        {
            if (cv.isValid())
            {
                cv.print();
            }
            else
            {
                std::cout << "ERROR: CV is invalid" << std::endl;
            }
        }

        return 0;
}

