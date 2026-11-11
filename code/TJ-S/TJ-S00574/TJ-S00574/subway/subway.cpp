#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,d,z[505][250],s[250];
	long long m,q,k[250],a[550],y[505][250];
	cin>>c>>n>>m>>d>>q;
	for (int i=0;i<m;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>s[i];
		for (int j=0;j<s[i];j++){
			cin>>z[i][j]>>y[i][j];
		}
	}
	for (int k=0;k<q;k++){
		int st,ed,sl,el;
		long long ss,es;
		cin>>st>>ed;
		for (int i=0;i<n;i++){
			int flag=0;
			for (int j=0;j<s[i];j++){
				if (z[i][j]==st){
					ss=y[i][j]+a[st-1];
					if (flag==1){
						flag=2;
						break;
					}
					flag=1;
				}
				if (z[i][j]==ed){
					es=y[i][j]+a[ed-1];
					if (flag==1){
						flag=2;
						break;
					}
					flag=1;
				}
			}
			if (flag==2){
				break;
			}
		}
		cout<<ss+es<<endl;
	}
	return 0;
}
