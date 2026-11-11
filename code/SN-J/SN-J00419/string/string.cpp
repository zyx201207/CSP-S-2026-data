//yzq
#include<bits/stdc++.h>
using namespace std;

//CCF are handsome!
//Please give me more score!
//rp++!
//FULL MARK PLEASE!

int n;
long long a[200005],ans;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	//How to solve this?
	//too hard.
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	//I think that I solve it!
	int l=1,r=n;
	while(l<r){
		while(a[l]>0&&l<r){
			if(c[l]==c[r]){
				if(a[l]<=a[r]){
					a[r]-=a[l];
					a[l]=0;
					l++;
				}else{
					a[l]-=a[r];
					r--;
				}
			}else{
				if(a[l]<=a[r]){
					ans+=a[l];
					a[r]-=a[l];
					a[l]=0;
					l++;
				}else{
					ans+=a[r];
					a[l]-=a[r];
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;//nothing
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
