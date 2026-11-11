#include<bits/stdc++.h>
using namespace std;

bool is_have(vector<int> &a, int b)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
        return true;
    }
    return false;
    
}
int main()
{
    auto f_in = ifstream("./card.in", ios::in);
    auto f_out = ofstream("./card.out", ios::out);

    int n, m;
    f_in >> n >> m;

    vector<int> pai(n);
    for (size_t i = 0; i < n; i++)
    {
        f_in >> pai[i];
    }

    map<int,int> count;
    for (size_t i = 1; i <= n; i++)
    {
        map<int, bool> have;
        stack<int> st;
        for (size_t j = i - 1; j < n; j++)
        {
            
            if (have[pai[j]])
            {
                 while (!st.empty() && st.top() != pai[j])
                {
                    have[st.top()] = false;
                    st.pop();
                   
                    
                }
                if (!st.empty())
                {
                    st.pop();
                }
                
               
            }
            st.push(pai[j]);
            have[pai[j]] = true;
            
        }

        
        have.empty();
        while (!st.empty())
        {
            if (have[st.top()])
            {
                count[st.top()]++;
                have[st.top()] = true;
            }
            st.pop();
        }
    }

    for (size_t i = 1; i <= m; i++)
    {
        f_out << count[i] << " ";
    }
    // for (int num : count.key_comp())
    // {
    //     f_out << num
    // }
    

    return 0;
}