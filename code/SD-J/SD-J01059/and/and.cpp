#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
struct node{
	char num[25];
	int sum;
	int a;
} a[maxn];
int n,m;
int maxl,maxx;
ll ans;
int maxp;
bool cmp(node A,node B){
	if(A.sum!=B.sum){
		return A.sum>B.sum;
	}
	else{
		int suma=0,sumb=0;
		for(int i=20-maxl+1;i<=20;i++){
			if(A.num[i]=='1'){
				suma++;
			}
			if(B.num[i]=='1'){
				sumb++;
			}
			if(suma!=sumb){
				return suma>sumb;
			}
		}
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;//n个数，选m个 
	for(int i=1;i<=n;i++){
		cin>>a[i].a;//读入 
		if(a[i].a>maxx){//找最大值，方便确定取‘1’的数量的范围 
			maxx=a[i].a;//更新最大值 
			maxp=i;//更新位置 
		}
	}
	swap(a[1],a[maxp]);//将最大值挪到最前面，方便后续操作 
	for(int i=1;i<=n;i++){//二进制拆分 
		int k=1;
		int cnt=20;
		int aa=a[i].a;
		while(aa!=0){
			a[i].num[cnt]=aa%2+'0';
			if(aa%2==1){
				a[i].sum++;
			}
			cnt--;
			aa=aa/2; 
		}
		if(i==1){
			maxl=cnt;
			continue;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=(ll)(a[1].a);
	for(int i=1;i<=m;i++){
		ans&=a[i].a;
	}
	cout<<ans;
	return 0;
}

