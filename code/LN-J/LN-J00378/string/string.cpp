#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct {
	int x;
	char c;
} s[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //clock_t st=clock();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>s[i].x>>s[i].c;
	int l=1,r=n;
	int ans=0;
	while(l<r){
		int num=min(s[l].x,s[r].x);
		if(s[l].c!=s[r].c) ans+=num;
		s[l].x-=num,s[r].x-=num;
		if(s[l].x==0) l++;
		if(s[r].x==0) r--;
	}
	cout<<ans;
	//cout<<endl;
	//clock_t end=clock();
	//double sec=double(end-st)/CLOCKS_PER_SEC;
	//if(sec>=1) cout<<"TLE "<<sec<<endl;
	//else cout<<"AC"<<endl;
    return 0;
}
