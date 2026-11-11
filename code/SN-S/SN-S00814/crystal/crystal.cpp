#include<bits/stdc++.h>
using namespace std;
int c;
int a[50005];
int n,m;
int sum;
int ss(int x){
	for(int i=n/2;i<n;i++){
		if(x==a[i]){
			sum++;
//			cout<<2<<" "<<a[i]<<endl;
//			cout<<sum<<endl;
		}else{
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
	int c=a[n/2];
//	cout<<c<<endl;
	int ans=0;
	ss(c);
	for(int i=0;i<n/2;i++){
		ans+=abs(c-a[i]);
		if(ans<=m){
			sum++;
//			cout<<1<<" "<<a[i]<<endl;
//			cout<<sum<<endl;
		}else{
			break;
		}
		if(m-ans!=0){
			for(int i=n/2;i<2;i++){
				ans+=abs(c-a[i]);
				if(ans<=m){
					sum++;
				}else{
					break;
				}
			}
		}
	}
	cout<<sum<<endl;
//	int minz=0,mini,minj;
//	int i,j;
//	for(i=0,j=n/2;i<n/2,j<n;){
//		mini=abs(c-a[i]);
//		minj=abs(c-a[j]);
//		cout<<c<<endl;
//		cout<<a[j]<<endl;
//		cout<<minj<<endl;
//		cout<<endl;
//		cout<<endl;
//		cout<<mini<<" "<<a[i]<<endl;
////		cout<<minj<<" "<<a[j]<<endl;
////		cout<<j<<endl;
//		if(mini>minj){
//			cout<<endl;
//			cout<<endl;
//			cout<<mini<<" "<<minj<<endl;
//			j++;
//			ans+=minj;
//			if(ans<=m){
//				sum++;
////				cout<<1<<endl;
////				cout<<mini<<" "<<minj<<" "<<a[j]<<endl;
////				cout<<j<<endl;
//			}else{
//				break;
//			}
//		}else if(mini==minj){
//			i++;
//			j++;
//			ans=ans+minj+mini; 
//			if(ans<=m){
//				sum+=2;
//				cout<<2<<endl; 
//				cout<<mini<<" "<<minj<<" "<<a[i]<<endl;
//				cout<<mini<<" "<<minj<<" "<<a[j]<<endl;
//			}else{
//				break;
//			}
//		}else if(minj<mini){
//			i++;
//			ans+=mini;
//			if(ans<=m){
//				sum++;
//				cout<<3<<endl;
//				cout<<mini<<" "<<minj<<" "<<a[i]<<endl;
//			}else{
//				break;
//			}
//		}
//	}
//	cout<<sum<<endl;
	return 0;
} 
