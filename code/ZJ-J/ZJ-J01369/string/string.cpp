#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
//	cout<<"fdsfdsfsfs "<<n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		b[i]=a[i];
//		cout<<"sfdffas\n\n";
	}
	long long l=1,r=n,aa=0,bb=0,ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(aa+a[l]<bb+a[r]){
				a[r]-=a[l];
				bb+=a[l];
				aa+=a[l];
				l++;
			}else if(aa+a[l]>bb+a[r]){
				a[l]-=a[r];
				aa+=a[r];
				bb+=a[r];
				r--;
			}else if(aa+a[l]==bb+a[r]){
				aa+=a[l];
				bb+=a[r];
				a[l]=a[r]=0;
				l++;
				r--;
			}
//			cout<<"balei"<<" fdssfd ";
//			cout<<"l: "<<l<<" r: "<<r<<endl;
			
		}else{
			if(aa+a[l]<bb+a[r]){
				ans+=a[l];
				aa+=a[l];
				bb+=a[l];
				a[r]-=a[l];
				l++;
			}else if(aa+a[l]>bb+a[r]){
				ans+=a[r];
				bb+=a[r];
				aa+=a[r];
				a[l]-=a[r];
				r--;
			}else if(aa+a[l]==bb+a[r]){
				ans+=a[l];
				aa+=a[l];
				bb+=a[r];
				a[l]=a[r]=0;
				l++;
				r--;
			}
//			cout<<"l: "<<l<<" r: "<<r<<endl;
//			cout<<"aa: "<<aa<<" bb: "<<bb<<endl;
		}
//					cout<<"l: "<<l<<" r: "<<r<<endl;
//		cout<<"ans: "<<ans<<endl<<endl;
	}
	cout<<ans;
	return 0;
}