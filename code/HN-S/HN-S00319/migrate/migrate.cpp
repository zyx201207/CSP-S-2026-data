#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[2000005],ans;
bool find(int x,int len){
	int s=x;int e=n;
//	cout<<"\n <->"<<x<<" "<<len<<"\n";
	while(s<e ){
		int mid=((s+e-1)>>1)+1;
//		cout<<mid<<" ";
		if(mid==e) break;
		if(a[mid]-a[x]>len) e=mid;
		else if(a[mid]-a[x]<len) s=mid;
		else return true;
	}
	return false;
}
int main(){ // ³ö´í  
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int len=a[j]-a[i];
				
				if(len%2==0) continue;
				if(len<=d) continue;
				
				if(len-1!=0) if(find(i,(len+1)/2) && find(i,(len-1)/2)){
					ans++;
				} 
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
