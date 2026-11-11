#include<bits/stdc++.h>
using namespace std;
int a[2000100];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;//×Ü×Ö·û´® 
	long long n,lei=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		string b;
		cin>>a[i]>>b;
		s+=b;
	}

	long long l=1,r=n;
	for(int i=0;i==0;){
		if(s[l-1]!=s[r-1]){
			if(a[l]>a[r]){
				lei+=a[l]-a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				lei+=a[r]-a[l];
				a[r]-=a[l];
				l++;
			}else{
				lei+=a[r];
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}
	
	if(l>=r)break;
	}
//	while(l>=r){cout<<"^";
//		if(s[l-1]!=s[r-1]){cout<<"#";
//			if(a[l]>a[r]){cout<<"* ";
//				lei+=a[l]-a[r];
//				a[l]-=a[r];
//				r--;
//			}else if(a[l]<a[r]){cout<<"** ";
//				lei+=a[r]-a[l];
//				a[r]-=a[l];
//				l++;
//			}else{
//				lei+=a[r]-a[l];
//				l++;
//				r--;
//			}
//		}else{
//			if(a[l]>a[r]){
//				a[l]-=a[r];
//				r--;
//			}else if(a[l]<a[r]){
//				a[r]-=a[l];
//				l++;
//			}else{
//				l++;
//				r--;
//			}
//		}
//	}
	cout<<lei;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//3
//2 a
//2 b

