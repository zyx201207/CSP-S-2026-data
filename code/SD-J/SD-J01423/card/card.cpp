#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt;
struct node{
	long long id,num;
};
long long s[500001],t[300001];
node d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	for(int o=1;o<=n;o++){
		for(int i=o;i<=n;i++){
			if(d[s[i]].id==1){
				for(int j=d[s[i]].num;j<=i;j++){
					d[s[j]].num=0;
					d[s[j]].id=0;
				}
				d[s[i]].id=1;
				d[s[i]].num=i;
			}else{
				d[s[i]].num=i;
				d[s[i]].id=1;
			}
		}
		for(int i=1;i<=300001;i++){
			if(d[i].id==1){
				t[i]++;
			}
			d[i].num=0;
			d[i].id=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 
