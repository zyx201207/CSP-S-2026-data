#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long num;
	char c;
}a[2000005];
long long n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].c;
	}
	long long l=1,ll=0,r=n,rr=0;
	while(l<=r){
		if(l>r)break;
		if(a[l].c==a[r].c){
			if((a[l].num-ll)>(a[r].num-rr)){
				ll=ll+(a[r].num-rr);
				r--;
				rr=0;
			}
			else if((a[l].num-ll)==(a[r].num-rr)){
				l++;
				r--;
				ll=0;
				rr=0;
			}
			else{
				rr=rr+(a[l].num-ll);
				l++;
				ll=0;
			}
		}
		else{
			if((a[l].num-ll)>(a[r].num-rr)){
				sum=sum+(a[r].num-rr);
				ll=ll+(a[r].num-rr);
				r--;
				rr=0;
			}
			else if((a[l].num-ll)==(a[r].num-rr)){
				sum=sum+a[l].num-ll;
				l++;
				r--;
				ll=0;
				rr=0;
			}
			else{
				sum=sum+(a[l].num-ll);
				rr=rr+(a[l].num-ll);
				l++;
				ll=0;
			}
		}
	}	
	cout<<sum; 
	return 0;
}
