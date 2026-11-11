#include <bits/stdc++.h>
using namespace std;
struct node{
	long long  m,t,s;
};
node arr[200001];
bool cmp(node a,node b){
	if(a.t==b.t) return a.s>=b.s;
	return a.t>=b.t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m1;
	scanf("%d%d",&n,&m1);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i].m);
		long long  x=arr[i].m;
		long long  j=0;
		while(x){
			j++;
			if(x%2==1){
				arr[i].s++;
				arr[i].t=j;
				
			}
			x/=2;
			//cout<<1;
		}
	}
	sort(arr+1,arr+n+1,cmp);
	//for(int i=1;i<=n;i++){
	//	cout<<arr[i].m<<' '<<arr[i].s<<' '<<arr[i].t<<endl;
	//}
	long long a=arr[1].m;

	for(int i=2;i<=m1&&i<=n;i++){
		//cout<<1;
		int b=a&arr[i].m;
		if(b==0){
			m1++;
			continue;
		}
		a=a&arr[i].m;
	}
	cout<<a;
	return 0;
} 
