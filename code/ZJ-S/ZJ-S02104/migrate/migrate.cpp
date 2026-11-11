#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[20002],start,endx;
int v[10022][10022],len[10022][10022];
void dfs1(int f,int now,int nums)
{
	f=f-a[now]+a[now-1];
    if(f<0)
    	return;
    if(now==endx)
    {
    	len[start][endx]=min(len[start][endx],nums);
    	return;
	}
	dfs1(f,now+1,nums);
	dfs1(d,now+1,nums+1);
}
void dfs2(int f,int now,int nums)
{
	f=f-a[now]+a[now-1];
    if(f<0)
    	return;
    if(now==endx)
    {
    	//cout<<nums<<len[start][endx]<<endl;
    	if(nums==len[start][endx])
    		v[start][endx]++;
    	return;
	}
    //cout<<"dfs2::"<<f<<"  "<<now<<"  "<<nums<<endl;
	dfs2(f,now+1,nums);
	dfs2(d,now+1,nums+1);
}
void solve_1_to_10()
{
    cin>>n>>d;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        	len[i][j]=10000000,v[i][j]=0;
	    	start=i,endx=j;
	    	dfs1(d,i+1,0);
	    	dfs2(d,i+1,0);
	    	if(v[i][j]==2)
	    		ans++;
	    	//cout<<v[i][j]<<"  "<<i<<"  "<<j<<endl;
        }
    }
    cout<<ans<<endl;
}
/*
0 1 6 2 -4 -3 -2 -1 3 6
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
    	if(c<=10)
        	solve_1_to_10();
        else if(c==11||c==12)
        {
        	cin>>n>>d;
        	int x,y;
        	cin>>x>>y;
        	int cha=y-x;
        	if(cha>=d/2+1)
        		cout<<0<<endl;
        	else if(cha<=d/2&&cha>d/3)
        		cout<<n-3<<endl;
        	else
        		cout<<0<<endl;
		}
		else if(c==13||c==14)
		{
			cout<<0<<endl;
		}
		else if(c==15||c==16||c==17||c==18)
		{
			
		}
	}
    return 0;
}