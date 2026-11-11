#include <bits/stdc++.h>
using namespace std;
int num[1000001];
int c[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	} 
	for(int k=1;k<=a;k++){
		int d[100001];
		int l=k,t=k;
		for(int i=k;i<=a;i++){
			d[t]=c[i];
			t++;
			for(int j=l;j<t-1;j++){
//				cout<<d[j]<<" ";
				if(d[i]==d[j]){
					l=t-1;
//					t++;
				}
			}
//			cout<<endl;
		}
//		cout<<endl;
		for(int i=l;i<t;i++){
//			cout<<d[i]<<" "<<k;
			num[d[i]]+=1;
		}
	}
	for(int i=1;i<=b;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
