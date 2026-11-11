#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005];
int x,y;
//int s[500005];
//int num1[500005],num2[500005];
int k1,k2,k3,k4,k5,k6;
long long ans;
int l(int x,int y){
	for(int j=x;j<=y;j++){
		ans+=t[1][j];
		return ans;
		
	}
	
	/*if(k3!=k4){
		for(int i=k5;i<=k1;i++){
			ans+=t[k3][i];
		}
		for(int i=k6;i<=k2;i++){
			ans+=t[k4][i];
		}
		return ans;
	}*/
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>k[i];//di tie zhan shu
		for(int j=1;j<=2*k[i];j++){
			cin >>a[i][j]>>t[i][j];//ting dao tai
			//s[a[i][j]]++;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=2*k[i];j++){
			if(s[a[i][j]]>1){
				k1=1;
			    k2=j;//cun jiao dian
			}	
		}
	}*/
	for(int i=1;i<=q;i++){
		cin >>x>>y;
		
		cout<<w[x]+w[y]+l(x,y)<<endl;
	}
	return 0;
}
