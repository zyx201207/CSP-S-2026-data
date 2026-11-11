#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        cerr<<i<<' '<<s[i]<<endl;
    }
    if(s[0]==s[7]&&s[1]==s[8]){
        cout<<1;
        if(s[3]==s[10]&&s[4]==s[11]){
            cout<<1;
            bool flag1=('A'<=s[5]&&s[5]<='C'&&'A'<=s[12]&&s[12]<='C');
            bool flag2=('D'<=s[5]&&s[5]<='F'&&'D'<=s[12]&&s[12]<='F');
            if(flag1||flag2){
                cout<<1;
                if(s[5]>s[12])swap(s[5],s[12]);
                if(s[5]=='A'&&s[12]=='B'||s[5]=='B'&&s[12]=='C'||s[5]=='D'&&s[12]=='F'){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
//0 1   0 1 A   0 2   0 2 B
//0 1 2 3 4 5 6 7 8 9 101112

/*
OK I'm gonna write a sketch about my csp-j2026 second round.

When I'm doing the first question I had a problem with my computer and had to restart it. But it seemed that I did something wrong, since the guard called the technician for help. Anyway soon I found the problem: In Linux, both "exe"s and folders have no typenames. So it didn't break down, it's just a small mistake for not knowing Linux well.

First and second questions are easy and I expect both full marks.

I tried to solve subtasks one by one on the third question because I'm not so familiar with bitand. I did the first 50pts and went to question 4. I tried greedy algorithm but eventually I found that it was partly wrong. Thus I used this algorithm for some subtasks and brutal algorithm for the others. I abandoned STL because it was too slow. Finally I expect 60pts for the fourth question.

And then I found out the solution of a subtask for the third question. The numbers had only 4 statuses. So I managed to get 10pts more.

My final expectation is 100+100+60+60=320. It's 9pts lower than last year.
*/
