/*
对于任意一个数列，分解为N个等差数列，从公差最小的开始处理

然后等差数列的结论是解 \sum{N}{i} \leq \frac{m}{公差}，其中N为答案

最后递归算N的和（发现太难写，先写个暴力）

算了，相较于后面那些题目，还是这个吧……
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

// 算了，为了考试方便，还是不用迭代器了
// bool check(vector<int>::iterator &begin,vector<int>::iterator &end)
// {
//     for(auto )
// }

// int get_dis()// 获取一段等差数列的公差

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<int> a(n+1);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     if(check(a.begin(),a.end()))
//     {
//         int d=get_dis(a.begin(),a.end())
        
//     }
// }

#define ERROR -1

#define Unknow -2

int get_d(vector<int> &a,int fi,int ed) // 算了，防止没有调用拷贝构造，还是稳妥一些吧（怕卡常）
{
    return (ed>=fi+1?a[fi+1]-a[fi]:ERROR);
}

int solve(vector<int> &a,int fi,int ed,int m)
{
    int d=get_d(a,fi,ed);
    if(ERROR == d) return ERROR;
    const int maxx = ceil(m/d);
    int ans=0,sum=0;
    for(int i=1;i<=maxx;i++)
    {
        sum += i;
        if(sum <= maxx) ans++;
        else return ans+1;
    }
    return ERROR;
}

bool check(vector<int> &a,int fi,int ed)
{
    if(ed >= fi+3){
    const int maxx=ed-fi;
    int dis=a[fi+1]-a[fi];
    for(int i=2+fi;i<ed;i++)
    {
        if(a[i+1]-a[i] != dis) return false;
    }return true;}
    else if(ed >= fi +2)
    {
        return (a[fi+1]-a[fi] == a[fi+2] - a[fi+1]);
    }
    else if(ed >= fi +1) return true;
    else
    return ERROR;
}

struct Node
{
    pair<int,int> fi=make_pair(0,0),ed=make_pair(0,0);
    int dis=Unknow;
    explicit Node(){fi=make_pair(0,0);ed=make_pair(0,0);dis=Unknow;}
    explicit Node(pair<int,int> a,pair<int,int> b,int c){fi=a;ed=b;dis=c;}
    ~Node() = default;
};

bool cmp(const Node &A,const Node &B) // 算了，还是手写吧，别用多态了
{
    if(A.dis != B.dis )
    return A.dis < B.dis;
    else
    {
        return A.fi.first < B.fi.first;
    }
}

ostream &operator << (ostream &out, Node &x)
{
    out<<"fi.num: "<<x.fi.first<<" fi.val: "<<x.fi.second<<" ed.num: "<<x.ed.first<<" ed.val: "<<x.ed.second<<" diss: "<<x.dis;
    return out;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end(),[](const int &x,const int &y)->bool{return x<y;});
    if(check(a,1,n))
    {
        cout<<solve(a,1,n,m);
    }
    else
    {
        int ans=0;
        vector<Node> dis(n+1,Node());
        for(int i=2;i<=n;i++)
        {
            dis[i-1]=Node(make_pair(a[i],i),make_pair(a[i-1],i-1),a[i]-a[i-1]);
        }
        sort(dis.begin()+1,dis.end()-1,cmp);

        // for(int i=1;i<n;i++)
        // {
        //     cout<<dis[i]<<endl;
        // }

        int lst = dis[1].dis;
        vector<vector<int>> que(n,vector<int>(n*2));

        // for(auto i:que)
        // {
        //     for(auto j:i)
        //      cout<<j<<' ';
        //      cout<<endl;
        // }

        int idx = 1;
        queue<int> d;d.push(lst);
        for(int i=1;i<n;i++)
        {
            int val = dis[i].dis;
            if(val == lst)
            {
                que[idx].push_back(dis[i].fi.first);
                que[idx].push_back(dis[i].ed.first);
            }
            else
            {
                idx ++;
                que[idx].push_back(dis[i].fi.first);
                que[idx].push_back(dis[i].ed.first);
                d.push(lst);
            }

        //     cout<<"i: "<<i<<endl<<"------------------------"<<endl;
        //     for(auto i:que)
        // {
        //     for(auto j:i)
        //      cout<<j<<' ';
        //      cout<<endl;
        // }
        // cout<<idx<<endl;
        //     cout<<endl<<"------------------------"<<endl;


        }
        for(int id=1;id<=idx;id++)
        {
            int new_size = unique(que[id].begin(),que[id].end()) - que[id].begin();
            int cha=d.front();
            d.pop();
            for(int i=1;i<=new_size/2;i++)
            {
                if(m > cha )
                {
                    ans ++;
                    m -= cha;
                }
            }
        }
        cout<< (ans>n?n:ans);
    }
    return 0;
}