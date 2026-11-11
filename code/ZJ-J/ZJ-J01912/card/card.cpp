#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
string q;
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i-1]=q[i];
	}
	for(int i=1;i<=n;i++){
		string s=q;
		string x="";
		int y=x.size();
		for(int j=i;j<=n;j++){
			bool flag=false;
			int abcd=0;
			for(int k=0;k<y;k++){
				if(int(x[k])-97==a[j]){
					flag=true;
					abcd=k;
				} 
			}
			if(flag==false){
				x+=char(a[j]+97);
				y++;
			}
			else{
				x.erase(abcd,y-abcd);
				x+=char(a[j]+97);
				y=x.size();
			}
		}
		for(int j=0;j<y;j++){
			b[int(x[j])-97]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
