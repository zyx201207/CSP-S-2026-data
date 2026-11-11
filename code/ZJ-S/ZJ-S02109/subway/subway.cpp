#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int w[N+10];
int c,n,m,d,p,ant;
struct line{
	int a[1000];
	int t[1000];
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	line l[25];
	cin>>c>>n>>m>>d>>p;
	int z[25],s,f;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>z[i];
		for(int j=1;j<=z[i];j++) cin>>l[i].a[j]>>l[i].t[j];
	}
	for(int i=1;i<=p;i++){
		cin>>s>>f;
		int flag=1;
		for(int j=1;j<=n;j++){
			for(int q=1;q<=z[j];q++){
				if(l[j].a[q]==s){
					for(int k=q;k<=z[j];k++){
						
						ant+=l[j].t[k];
						if(l[j].a[k]==f) cout<<w[s]+w[f]+ant<<endl;
					}
					flag=0;
					break;
				}
			}
			if(!flag) break;
		}
	}
	return 0;
}