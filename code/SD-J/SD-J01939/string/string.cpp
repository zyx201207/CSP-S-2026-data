#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	long long ans=0;
	int l=1,r=n;
	long long cntl=a[l],cntr=a[r];
	char cl=s[l],cr=s[r];
	while(l<=r){
		if(cl!=cr){
			if(cntl>cntr){
				ans+=cntr;
				a[l]-=cntr;
				cntl-=cntr;
				a[r]=0;
				r--;
				cntr=a[r];
				cr=s[r];
			}
			else if(cntr>cntl){
				ans+=cntl;
				a[r]-=cntl;
				cntr-=cntl;
				a[l]=0;
				l++;
				cntl=a[l];
				cl=s[l];
			}
			else{
				ans+=cntr;
				a[r]=0,a[l]=0;
				r--,l++;
				cntr=a[r],cntl=a[l];
				cr=s[r],cl=s[l];
			}
		}
		else{
			if(cntl>cntr){
				cntl-=cntr;
				a[l]-=cntr;
				a[r]=0;
				r--;
				cr=s[r];
				cntr=a[r];
			}
			else if(cntr>cntl){
				cntr-=cntl;
				a[r]-=cntl;
				a[l]=0;
				l++;
				cl=s[l];
				cntl=a[l];
			}
			else{
				a[l]=0,a[r]=0;
				r--,l++;
				cntr=a[r],cntl=a[l];
				cr=s[r],cl=s[l];
			}
		}
	}
	cout<<ans;
	return 0;
}
