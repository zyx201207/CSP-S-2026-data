#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n;
struct str1{
	int x;
	char c;
}vis1[N];
struct str2{
	int x;
	char c;
}vis2[N];
int sum,ans,num;
int l=1,r=1;
bool flag;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>vis1[i].x>>vis1[i].c;
		vis2[n-i+1].x=vis1[i].x;
		vis2[n-i+1].c=vis1[i].c;
		sum+=vis1[i].x;
	}
	if(sum%2==0)flag=true;
	sum/=2;
	while(num<=sum){
        if(flag)if(num>=sum)break;
        if(vis1[l].x>vis2[r].x){
            vis1[l].x-=vis2[r].x;
            if(vis1[l].c!=vis2[r].c)ans+=vis2[r].x;
            num+=vis2[r].x;
            r++;
        }
        else if(vis1[l].x<vis2[r].x){
            vis2[r].x-=vis1[l].x;
            if(vis1[l].c!=vis2[r].c)ans+=vis1[l].x;
            num+=vis1[l].x;
            l++;
        }
        else if(vis1[l].x==vis2[r].x){
            if(vis1[l].c!=vis2[r].c)ans+=vis1[l].x;
            num+=vis1[l].x;
            l++;
            r++;
        }
	}
	cout<<ans;
	return 0;
}
