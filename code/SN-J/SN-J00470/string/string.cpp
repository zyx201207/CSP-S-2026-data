#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "string"//检查文件名
#define FIN freopen(PID".in","r",stdin)
#define FOUT freopen(PID".out","w",stdout)
int n,m,ans;
char js[27];
vector< pair<char,int> > v;
char a;

signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//记得开注释 检查文件名
	FIN;
	FOUT;
	cin>>n;
	int dj=1,u=0;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		//cout<<m<<a;
		u+=m;
		js[a]=m;
		v.push_back({a,m});
	}
	int l=0,r=v.size()-1;
	while(l<=r){
		//cout<<"2";
//		if(v[l].second==0){
//			l++;
//		}
//		if(v[r].second==0){
//			r--;
//		}
		if(v[l].first!=v[r].first){
			if(v[l].second<v[r].second){
				ans+=v[l].second;
				//cout<<"3"<<ans;
				v[r].second=v[r].second-v[l].second;
			//	v[l].second=0	
				l++;	
			}else{
			
				ans+=v[r].second;
				//cout<<"2"<<ans;	
				v[l].second=v[l].second-v[r].second;
			//	v[r].second=0;	
				r--;	
			}
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

