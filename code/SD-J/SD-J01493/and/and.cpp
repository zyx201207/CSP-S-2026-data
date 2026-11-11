#include<bits/stdc++.h>//sometimes it add to 0 and mistakes,经过修改,答案有时过大 ，从2倍到多1不等 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=5;//n all
	int m=5;//m you choose
	vector<long long>arr;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	sort(&arr[0],&arr[0]+n,cmp);
	if(m==1){
		cout<<arr[0];
		return 0; 
	}
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<' ';
//	}cout<<endl;
	long long ans=arr[0],tempans;
	tempans=ans;
	
	for(int i=0;i<m&&i<n;i++){
		if(ans&arr[i]!=0){
			ans&=arr[i];
		}
		else m++; 
	}
	cout<<ans;
//	int temp1=524288,temp2=262144;
//	temp1&=arr[1];
//	cout<<temp1<<"&"<<arr[1]<<endl;
//	temp2&=arr[0];
//	cout<<temp2<<"&"<<arr[0];
	return 0;
} 
/*样例 3、4、5failed 
	4 2
	3 15 12 12
	
	5 3
	31 3 1 15 7
	
	
	
*/
