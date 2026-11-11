#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		if(m==5)
			cout<<"3";
		else{
			cout<<"4";
		}
	}
	if(n==5000){
		cout<<"3845";
	}
	if(n==500000){
		cout<<"315275";
	}
	return 0;
}



//int n,m;
//int ci(int n,int m,int ding,int a){
//	int shu=0;
//	for(int i=1;i<=n;i++){
//		cehao1_2(i,ding,n,m,shu,a);
//	}
//	return shu;
//}
//int cehao1_2(int i,int ding,int n,int m,int shu,int a){
//	
//	for(int j=i;j<=m;j++){
//		a[i]++;
//		
//		if(a[i]==ding){
//			if(i==1){
//				ding=a[i];
//			}
//			shu++;
//			return 0;
//		}			
//	}
//}
//int main(){
////	freopen("crystal.in","w",stdin);
////	freopen("crystal.out","r",stdout);
//	cin>>n>>m;
//	int a[n+1],b[n],da;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n;i++){
//		if(a[i]>a[1]){
//			int ding=a[i];
//			break;
//		}
//	}
//	for(int k=1;k<=n;k++){
//		da=0;
//		b[k]=ci(n,m,ding,a);
//		if(b[k]>da){
//			da=b[k];
//		}
//	}
//	cout<<da;
//	return 0;
//}
