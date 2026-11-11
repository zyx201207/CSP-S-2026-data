#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,data[500002],sm[500002],ans;
bool check(int l,int r)
{
    int cst=(r-l+1)*data[r]-(sm[r]-sm[l-1]);
    //cout<<l<<' '<<r<<' '<<cst<<'\n';
    return cst<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    sort(data+1,data+n+1);
    for(int i=1;i<=n;i++)
        sm[i]=sm[i-1]+data[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(check(mid,i))
                r=mid;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}

/*
14:19   Waiting for contest to begin...
        Bored.
        Found that in Code::Blocks IDE when use mouse to hover above words it will show the description.
        Cool! A dictionary!
        Hmm,let me see what this will take me...
14:22
        What's a 'generic term'? Weird.
        Apparently 'taxonomic' means categorization or something like that.
14:25
        Bored. Waiting. I should just wait...and wait...and wait...
14:28
        A clock precise to the millisecond. Just what I need for a coding competition.
14:33
        Problem A seems simple.
        Let me try...
14:45
        Solved A!
        So simple that probably everyone solved it.
        B seems to be a graph problem. Let the nodes be the No. of the subway.
14:49
        Problem statement B makes me sad.
        Way to long.
14:57
        Why the problem order in the submitting system is different from the problem order in the statement???
15:00
        The real challenge in B is understanding the statement.
        Why this is a Floyd! But how will I build the graph...
15:02
        HOW WILL I BUILD THE GRAPH???
15:06
        1st:build a graph with n+m nodes.O(sigma k)=5*10^5
        2nd:for each subway line node run dij.O(n*dij)=O(500*forgot QAQ)
        3rd:use the results to build the graph for the subways.O(n^2)=2.5*10^5
        4th:run Floyd on the subway graph.O(n^3)=1.25*10^8                          is this possible?
        5th:read the query and print.O(q)=1*10^5
15:20
        No wait.
        1st:build a graph with n+m nodes.O(sigma k)=5*10^5
        2nd:build the graph for the subways.O(n*m*min(d,n))=5*10^8                  is this possible?
        3rd:run Floyd on the subway graph.O(n^3)=1.25*10^8                          is this possible?
        4th:read the query and print.O(q)=1*10^5
        Really,could anybody remember the time complexity of dij?
        (ans:everyone except me)
        7*10^8.Maybe?Let me calculate the min possible points earned when judge runs 1*10^8 per sec.
15:25
        At least 50 points. This is definitely Floyd, so I'm going to assume it will pass.
        3.2.1.Go! Start programming!
15:28
        Wait. Why is there a 'number of test case' input? For easier sub-solutions?
15:38
        Time complexity calculation non-optimal.
        2nd:build the graph for the subways.O(n*m*min(d,n))=5*10^8                  is this possible?
        ->
        2nd:build the graph for the subways.O(sigma k*min(d,n))=1*10^8
        Much better now!
        total estimate around 2.5*10^8.
15:45
        Oh no. Time complexity worse than I thought.
        4th:read the query and print.O(q)=1*10^5
        ->
        4th:read the query and print.O(q*d*d)=4*10^7
        Not much though.
        Re-calculation needed.
        1st:build a graph with n+m nodes.O(sigma k)=5*10^5
        2nd:build the graph for the subways.O(sigma k*min(d,n))=1*10^8
        3rd:run Floyd on the subway graph.O(n^3)=1.25*10^8                          is this possible?
        4th:read the query and print.O(q*d*d)=4*10^7
        Total equal to around 3*10^8.
        Maybe?
15:50
        Version 1 of B done!
16:35
        B passed all large samples.
        Time longest 0.5 s-probably no TLE.
16:37
        answer to the password:today is not Christmas.
17:06
        Wait, half an HOUR just passed? Man I should not have started that Tetris game.⪓⪓⪓⪓⪓⪓
18:20
        Could not solve C.
        100+100+0+0=200
        Gonna test A&B.
*/
