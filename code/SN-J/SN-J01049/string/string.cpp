#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int s;
	char c;
};
int n,ans;
vector<node>ve;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int s;
		char c;
		cin>>s>>c;
		if(ve.size()==0||ve[ve.size()-1].c!=c)ve.push_back({s,c});
		else ve[ve.size()-1].s+=s;
	}
	int i=0,j=ve.size()-1;
	while(i<j){
		int tmp=min(ve[i].s,ve[j].s);
		if(ve[i].c!=ve[j].c)ans+=tmp;
		ve[i].s-=tmp;
		ve[j].s-=tmp;
		if(ve[i].s==0)i++;
		if(ve[j].s==0)j--;
	}
	cout<<ans<<endl;
	return 0;
}
