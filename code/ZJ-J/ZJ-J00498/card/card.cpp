#include<bits/stdc++.h>
using namespace std;
const int maxk=5e5+7,maxn=3e5+7;

int n,m,j,fir[maxk];
struct _{
	int id,point;
	bool u;
};
_ a[maxk];

int tmp[maxn];
bool cmp(_ x,_ y){
	return x.id<y.id;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].point);
		a[i].id=i;
	}
	int tmpp=n;
	while(tmpp--){
		int car[maxk]={};
		memset(fir,sizeof fir,0);
		j++;
		for(int i=j-1;i<n;i++){
			if(car[a[i].point]==0){
				car[a[i].point]++;
				fir[a[i].point]=i;
			}
			else {
				for(int l=fir[a[i].point];l<i;l++){
					car[a[l].point]=0;
				}
				car[a[i].point]++;
				fir[a[i].point]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(car[i]>0){
				tmp[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",tmp[i]);
	}
	return 0;
}