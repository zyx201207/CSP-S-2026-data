#include<bits/stdc++.h>
using namespace std;
struct sch{
	long long a;
	char c;
}a[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n;
	int cnt1=a[1].a,cnt2=a[n].a;
	char lx=a[1].c;
	char ly=a[n].c;
	while(cnt1+cnt2>1&&l<r){
		if(lx==ly){
			if(cnt1>cnt2){
				cnt1-=cnt2;
				r--;
				cnt2=a[r].a;
				ly=a[r].c;
			}
			else if(cnt2>cnt1){
				cnt2-=cnt1;
				l++;
				cnt1=a[l].a;
				lx=a[l].c;
			}
			else{
				l++;
				r--;
				cnt1=a[l].a;
				lx=a[l].c;
				cnt2=a[r].a;
				ly=a[r].c;
			}
		}
		else {
			if(cnt1>cnt2){
				ans+=cnt2;
				cnt1-=cnt2;
				r--;
				cnt2=a[r].a;
				ly=a[r].c;
			}
			else if(cnt2>cnt1){
				ans+=cnt1;
				cnt2-=cnt1;
				l++;
				cnt1=a[l].a;
				lx=a[l].c;
			}
			else{
				ans+=cnt1;
				l++;
				r--;
				cnt1=a[l].a;
				lx=a[l].c;
				cnt2=a[r].a;
				ly=a[r].c;
			}
		}
	}
	cout<<ans;
	return 0;
}
