#include <bits/stdc++.h>
using namespace std;
struct ST
{
    long long l,r;
    char c;
};
ST a[200005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	a[0].r=0;
	for (int i=1;i<=n;i++){
		long long msk=0;
		cin>>msk>>a[i].c;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+msk-1;
	}
	long long leftx=1,rightx=n,left=1,right=a[n].r;
	while (leftx<rightx){
			long long lenl=a[leftx].r-left+1;
			long long lenr=right-a[rightx].l+1;
		    if (a[leftx].c!=a[rightx].c)  cnt+=min(lenl,lenr);
		    //cout <<left<<" "<<right<<"\n";
			if (lenl<lenr){
				leftx++;
				left=a[leftx].l;
				right-=lenl;
			}
			else if (lenr<lenl){
				rightx--;
				right=a[rightx].r;
				left+=lenr;
			}
			else{
				leftx++;
				rightx--;
				left=a[leftx].l;
				right=a[rightx].r;
			}
	}
	cout <<cnt;
	return 0;
}//cbbaa
// aabbc
// 