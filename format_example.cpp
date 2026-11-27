#include <iostream>

enum class Statistic
{
    Count,
    Total,
};

class ScoreSummary
{
public:
    void add(int score)
    {
        if (score < 0)
            return;

        total_ += score;
        ++count_;
    }

    int value(Statistic statistic) const
    {
        switch (statistic)
        {
        case Statistic::Count:
            return count_;
        case Statistic::Total:
            return total_;
        }

        return 0;
    }

private:
    int count_ = 0;
    int total_ = 0;
};

int main()
{
    const int scores[] = {86, -1, 92, 100};
    const int *first = scores;

    ScoreSummary summary;
    for (int score : scores)
        summary.add(score);

    std::cout << "First score: " << *first << '\n'
              << "Valid scores: " << summary.value(Statistic::Count) << '\n'
              << "Total score: " << summary.value(Statistic::Total) << '\n';
    return 0;
}
