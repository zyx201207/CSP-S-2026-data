#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	long long num;
	char l;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].l;
	}
	int l=1,r=n;
	long long cnt=0;
	long long sum=a[l].num;
	char lt=a[l].l;
	while(l<r){
		if(sum>0){
			
			if(a[r].l!=lt){
				cnt+=min(a[r].num,abs(sum));
				
			}
			sum-=a[r].num;
			if(sum<0){
				lt=a[r].l;
				l++;
			}	
			else if (sum>0){
				r--;
			}		
		}
		else if (sum<0){
			if(a[l].l!=lt){
				cnt+=min(a[l].num,abs(sum));
				
			}
			sum+=a[l].num;
			if(sum>0){
				lt=a[l].l;
				r--;
			}else if (sum<0){
				l++;
			}
		}
		if (sum==0){
			l++;
			r--;
			sum=a[l].num;
			lt=a[l].l;
		}
	}
	
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

