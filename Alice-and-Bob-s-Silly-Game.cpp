#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sillyGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

// from https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/forum by RAZAK_123
string sillyGame(int n)
{
    if (n == 1)
    {
        return "Bob";
    }
    
    int dp[n+1];
    dp[0] = 0 ;
    dp[1] = 0 ;
    dp[2] = 1 ;
    
    for (int i = 3; i <= n; ++i)
    {
        if (i & 1)
        {
            dp[i] = 1;
        }
    }
    
    for (int i = 2; i <= sqrt(n); ++i)
    {
        for (int j = 2; i*j <= n; ++j)
        {
            dp[i*j] = 0;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (dp[i])
        {
            cnt++;
        }
    }
    
    return (cnt&1) ? "Alice" : "Bob";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = sillyGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
