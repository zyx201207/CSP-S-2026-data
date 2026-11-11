//#include<bits/stdc++.h>
//using namespace std;
//long long a[200001],tong[200001];
////char c[200001];
//int find1(vector<long long>wan,long long aa){
//	for(int i=0;i<wan.size();i++){
//		if(wan[i]==aa){
//			return i;
//		}
//	}
//	return 0;
//}
//int main(){
////	freopen("card.in","r",stdin);
////	freopen("card.out","w",stdout);
//	long long n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n;i++){
//		vector<long long>wan;
//		for(int j=i;j<=n;j++){
//			int ii=find1(wan,a[j]);
//			if(ii){
//				for(int q=ii;q<wan.size();q++){
//					wan.clear(q);
//				}
//			}
//			wan.push_back(a[j]);
//			for(long long it:wan)cout<<it<<" ";
//			cout<<endl;
//		}
//		for(long long it:wan)tong[it]++;
////		cout<<endl<<endl;
//	}
////	cout<<"afsdj;jfsadf\n\n\n\n";
//	for(int i=1;i<=m;i++){
//		cout<<tong[i]<<" ";
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
long long a[200001],tong[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		if(a[i]!=a[i+1]){
			tong[a[i]]=i;
//		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}

























