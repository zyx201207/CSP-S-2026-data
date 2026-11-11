#include<bits/stdc++.h>
using namespace std;
struct mw{
	int a,c;
};
int n,m;
int b[300005]={0};
mw num[500005]={0};
int main(){
freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i].a;
	}
	for(int i=1;i<=n;i++){
		int c[300005]={0};
	for(int y=i;y<=n;y++){
		c[num[y].a]++;
		if(c[num[y].a]==2){
	for(int z=y-1;z>=i;z--){
		if(num[z].a==num[y].a){
					num[z].c=1;
					c[num[z].a]--;
					break;
				}
				num[z].c=1;
				c[num[z].a]--;
			}
		}
	}
	for(int y=i;y<=n;y++){
		if(num[y].c==0){
			b[num[y].a]++;
		}
		num[y].c=0;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
