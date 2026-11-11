#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,INF=1e9;
int a[N],f[N][N],ff[N][N],f3[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,ans=0,c=0,f=1;
		cin>>n>>d;
		vector<int>ve,ve2,ve3;
		set<int>se1,se2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			if(!c)c=a[i]-a[i-1];
			else if(a[i]-a[i-1]!=c)f=0;
		}
		if(f&&n>=5005){
			int gs=d/c;
			if(n<=gs||d<c)cout<<0<<"\n";
			//cout<<
			continue;
		}
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				int lst=x,cnt=0,c2=0,c3=0,pos=0,g=1;
				//cout<<x<<" "<<y<<"\n";
				for(int i=x+1;i<=y;i++){
					if(a[i]-a[i-1]>d)break;
					if(abs(a[lst]-a[i])>d){
						lst=i-1;
						cnt++;
						i--;
						ve.push_back(i);
						se1.insert(i);
					}
				}
				pos=y-1;
				while(abs(a[pos]-a[y])<=d&&pos>=x&&abs(a[lst]-a[pos])<=d)ve3.push_back(pos),pos--;
				if(lst!=y)cnt++,ve.push_back(y),se1.insert(y);//cout<<"pppp";
				lst=y;
				for(int i=y-1;i>=x;i--){
					if(a[i+1]-a[i]>d)break;
					if(abs(a[lst]-a[i])>d){
						ve2.push_back(lst);
						se2.insert(lst);
						lst=i+1;
						c3++;i++;
					}
				}
				if(lst!=x)c3++,ve2.push_back(lst),se2.insert(lst);
				pos=x+1;
				while(abs(a[pos]-a[x])<=d&&pos<=y&&abs(a[lst]-a[pos]<=d))ve3.push_back(pos),pos++;
				//cout<<cnt<<" "<<c3<<"\n";
				if(ve.size()==ve2.size()){
					sort(ve.begin(),ve.end());
					sort(ve2.begin(),ve2.end());
					//sort(ve3.begin(),ve3.end());
					int len=ve3.size();
					int f=0;
					for(int i=0;i<ve.size();i++){
						if(ve[i]!=ve2[i])f=1;
						//cout<<ve[i]<<" "<<ve2[i]<<"\n";
					}
					for(int i=0;i<len;i++){
						if(!se1.count(ve3[i])&&!se2.count(ve3[i]))g=0;
					}
					if(!f)c3=INF;
					//cout<<"\n";
				}
				if(cnt==c3&&g){
					ans++;
					//cout<<x<<" "<<y<<"\n";
				}
				ve.clear(),ve2.clear(),ve3.clear();
				se1.clear(),se2.clear();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 3
-2 -1 0 1 2

0 1
6 2
-4 -3 -2 -1 3 6
*/
