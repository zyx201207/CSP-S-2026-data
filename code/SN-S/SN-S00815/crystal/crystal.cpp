#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	double sum=0.0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i]; 
	}
	sum/=n;
	sum=floor(sum)+1;
	sum=int(sum);
	sort(a+1,a+n+1);
	int l=0;
	for(int i=n;i>=1;i--){
		if(sum>=a[i]){
			l=i;
			break;
		}
	}
	int x=0;
	
	/*if(abs(a[l-1]-a[l])>abs(a[l+1]-a[l])){
		x=a[l+1];
		l++;
	}else{
		x=a[l-1];
		l--;
	}*/
	int cnt=0;
	for(int i=l;i>=1;i--){
		if(x-a[i]<=m){
			m=m-(x-a[i]);
			cnt++;
		}
	}
	cout<<cnt;
	//cout<<l;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool ck(int x){
	int k=m;
	for(int i=x;i>=1;i--){
		if(m>=a[x]-a[i]){
			k-=(a[x]-a[i]);
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ck(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}*/
