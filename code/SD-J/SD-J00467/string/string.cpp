#include<bits/stdc++.h>
using namespace std;
long long a[200099],n,l,mid,cur,m,ans;
char c[200099];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	mid=(l+1)/2;
	for(int i=1;i<=n;i++){
		cur+=a[i];
		if(cur>=mid){
			m=i;
			break;
		}
	}
	int i=1,j=n;
	if(n==1) cout<<0;
	else if(n==2) {
	if(c[1]!=c[2]) cout<<min(a[1],a[2]);
	else cout<<0;
	}else{
		while(i<=m&&j>=m&&a[i]!=0&&a[j]!=0){
			if(i==j){
				break;}
			if(c[i]!=c[j]){
				if(a[i]>a[j]){
					ans+=a[j];
					a[i]-=a[j];
					a[j]=0;j--;
				}else if(a[i]<a[j]){
					ans+=a[i];
					a[j]-=a[i];
					a[i]=0;i++;
				}
				else{
					ans+=a[i];
					a[i]=0;
					a[j]=0;i++;j--;
				}
			}else{
				long long te=min(a[i],a[j]);
				a[i]-=te;
				a[j]-=te;
				if(!a[i]) i++;
				if(!a[j]) j--;
			}
		}
		cout<<ans;
	}

	return 0;
}

