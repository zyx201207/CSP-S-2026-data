#include<bits/stdc++.h>
using namespace std;
int s[500005];
int t[500005][500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	int max1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=500005;j++){
			cin>>t[j][i];
			if(j>=t[1][i]*2+1) break;
			if(max1<=t[1][i]) max1=t[1][i];
		}
	}
	for(int k=1;k<=q;k++){
		int num=0;
		int im=0;
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=max1*2+1;j+=2){
				if(t[j][i]==a+im){
					num+=t[j+1][i];
				}
				im+=1;
			}
		}
		if(im==b+1) break;
		num+=s[a]+s[b];
		cout<<num<<endl;
	}
	return 0;
}
	
