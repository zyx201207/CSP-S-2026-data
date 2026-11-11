#include<bits/stdc++.h>
using namespace std;
bool flag1=0,flag2=0;
int n,m,a[200005],b[200005][40],vis[200005],t[40];
//bool check(int x){
//	for(int i=1;i<=20;i++){
//		if(x==(1<<i)-1)return 1;
//	}
//	return 0;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(a[i]!=i-1)flag1=1;
//		if(!check(a[i]))flag2=1;
	}
//	if(m==1){
//		int ax=0;
//		for(int i=1;i<=n;i++){
//			ax=max(a[i],ax);
//		}
//		cout<<ax;
//		return 0;
//	}
//	if(m==2&&n<=4000){
//		int ax=0;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
////				if((a[i]&a[j])>ax){
////					cout<<a[i]<<" "<<a[j]<<"\n";
////					ax=a[i]&a[j];
////				}
//				ax=max(ax,a[i]&a[j]);
//			}
//		}
//		cout<<ax;
//		return 0;
//	}
//	if(!flag1){
//		int sum=a[n-m+1],B[40],ccnt=0;
//		for(int i=1;i<=32;i++)B[i]=0;
//		while(sum){
//			ccnt++;
//			if(sum%2==1){
//				B[ccnt]=1;
//			}
//			sum/=2;
//		}
//		//cout<<ccnt<<" ";
//		sum=(1<<ccnt)-1;
//		while(ccnt--){
//			if(!B[ccnt]){
//				break;
//			}
//		}
//		//cout<<ccnt<<" ";
//		cout<<sum-((1<<ccnt)-1);
//		return 0;
//	}
//	if(!flag2){
//		sort(a+1,a+n+1);
//		cout<<a[n-m+1];
//		return 0;
//	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=a[i],cnt=0;
		while(sum){
			cnt++;
			if(sum%2==1){
				b[i][cnt]=1;
				t[cnt]++;
			}
			sum/=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(t[i]>=m){
			for(int k=1;k<i;k++){
				t[k]=0;
			}
			for(int j=1;j<=n;j++){
				if(!b[j][i])vis[j]=1;
				if(!vis[j]){
					//cout<<a[j]<<" ";
					for(int k=1;k<i;k++){
						t[k]+=b[j][k];
					}
				}
			}
			//cout<<"\n";
		}
	}
	int ans=0,C=0;
	for(int i=n;i>=1;i--){
		if(C==m)break; 
		if(!vis[i])C++;
		if(!vis[i]&&!ans)ans=a[i];
		else if(!vis[i]&&ans)ans&=a[i];
	}
	cout<<ans;
	return 0;
}

