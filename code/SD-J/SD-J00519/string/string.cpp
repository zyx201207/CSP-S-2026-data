#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long a;
	string c;
}b[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool is_same=1;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		if(i!=1&&b[i].c!=b[i-1].c) is_same=0;
	}
	if(is_same){
		cout<<0<<"\n";
		return 0;
	}
	int left=1,right=n;
	long long ans=0;
	while(left<right){
		if(b[left].a>b[right].a){
			long long m=b[left].a,count=0;
			while(count!=m){
				if(count+b[right].a<=m){
					count+=b[right].a;
					if(b[left].c!=b[right].c){
						ans+=b[right].a;
					}
					right--;
				}else{
					b[right].a=b[right].a-(m-count);
					if(b[left].c!=b[right].c){
						ans=ans+(m-count);
					}
					count=m;
				}
			}
			left++;
		}else if(b[left].a==b[right].a){
			if(b[left].c==b[right].c){
				left++;
				right--;
				continue;
			}
			ans+=b[right].a;
			left++;
			right--;
		}else{
			long long m=b[right].a,count=0;
			while(count!=m){
				if(count+b[left].a<=m){
					count+=b[left].a;
					if(b[left].c!=b[right].c){
						ans+=b[left].a;
					}
					left++;
				}else{
					b[left].a=b[left].a-(m-count);
					if(b[left].c!=b[right].c){
						ans=ans+(m-count);
					}
					count=m;
				}
			}
			right--;
		}
		
	}
	cout<<ans<<"\n";
	return 0; 
} 
