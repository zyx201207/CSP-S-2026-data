#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int c=0;
		cin>>c;
		a.push_back(c);
	}
	int max1=0,ji1=0,ji2=0;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]&a[j]>max1){
				max1=a[i]&a[j];
				ji1=i,ji2=j;
			}
		}
	}
	a[ji1]=0,a[ji2]=0;
	int max2=0,ji3=0;
	for(int i=0;i<m-2;i++){
		for(int j=0;j<a.size();i++){
			if(a[j]==0){
				continue;
			}
			if(max1&a[j]>max2){
				max2= max1&a[j];
			    ji3=j;
			}
		}
		max1=max2;
		max2=0;
		a[ji3]=0;
		ji3=0;
    }
  cout<<max1;
	return 0;
}
