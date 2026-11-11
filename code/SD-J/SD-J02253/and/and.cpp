# include <bits/stdc++.h>
using namespace std;
long long n,m,arr[200005],sum,flag[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sum=arr[1]&arr[2];
	m-=2;
	int pos1,pos2;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(arr[i]&arr[j]>sum){
				pos1=i;
				pos2=j;
				sum=arr[i]&arr[j];
			}
		}
	}
	flag[pos1]=1;
	flag[pos2]=1;
	while(m--){
		long long maxn;
		for(int i=1;i<=n;i++){
			if(flag[i]==0){
				maxn=sum&arr[i];
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(flag[i]) continue;
			if(sum&arr[i]>maxn){
				pos1=i;
				maxn=sum&arr[i];
			}
		}
		flag[pos1]=1;
		sum=maxn;
	}
	cout<<sum;
	return 0;
} 
