#include<bits/stdc++.h>
using namespace std;
#define int long long
struct data{
	int num;
	char c;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<data> a(n+1); 
	int len = 0;
	int mid = 0;
	for(int i =0;i<n;i++){
		int tmp;
		char c;
		cin>>tmp;
		cin>>c;
		a[i].num=tmp;
		a[i].c=c;
		len += tmp;
	}
	int sum = 0;
	for(int i = 0; i<n;i++){
		sum += a[i].num;
		if(sum>(len/2)){
			for(int j = n;j > i + 1;j--){
				a[j]=a[j-1];
			}
			if(len%2==1){
				a[i+1].c=a[i].c;
				//cout<<a[i+1].c<<endl;
				a[i+1].num=sum-(len/2)-1;
				a[i].num-=(a[i+1].num+1);
			}else{
				a[i+1].c=a[i].c;
				
				a[i+1].num=sum-(len/2);
				a[i].num-=a[i+1].num;
			}
			mid = i;
			break;
		}
	}

	int ans = 0;
	int l1=0,l2=n;
	if(len%2==0){
		//cout<<1<<endl;
		for(int i = 0;i<mid;i++){
			if(a[l1].c == a[l2].c){
				if(a[l1].num==a[l2].num){
					++l1;
					--l2;
				}else{
					if(a[l1].num>a[l2].num){
						--l2;
						a[l1].num-=a[l2].num;
					}else{
						++l1;
						a[l2].num-=a[l1].num;
					}
				}
			}else{
				//cout<<a[l1].c<<a[l2].c<<endl;
				if(a[l1].num==a[l2].num){
					ans+=a[l1].num;
					++l1;
					--l2;
					
				}else{
					if(a[l1].num>a[l2].num){
						--l2;
						a[l1].num-=a[l2].num;
						ans+=a[l2].num;
					}else{
						++l1;
						a[l2].num-=a[l1].num;
						ans+=a[l1].num; 
					}
				}
			}
		}
	}else{
		for(int i = 0;i<=mid;i++){
			if(a[l1].c == a[l2].c){
				if(a[l1].num==a[l2].num){
					++l1;
					--l2;
				}else{
					if(a[l1].num>a[l2].num){
						--l2;
						a[l1].num-=a[l2].num;
					}else{
						++l1;
						a[l2].num-=a[l1].num;
					}
				}
			}else{
				//cout<<a[l1].c<<a[l2].c<<endl;
				if(a[l1].num==a[l2].num){
					ans+=a[l1].num;
					++l1;
					--l2;
					
				}else{
					if(a[l1].num>a[l2].num){
						--l2;
						a[l1].num-=a[l2].num;
						ans+=a[l2].num;
					}else{
						++l1;
						a[l2].num-=a[l1].num;
						ans+=a[l1].num; 
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
