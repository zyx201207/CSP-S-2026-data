#include<bits/stdc++.h>
using namespace std;
struct str{
	int cnt;
	int pos;
	int nums;
}arr1[200005];
bool cmp(str a,str b){
	if(a.nums!=b.nums) return a.nums>b.nums;
	else return a.cnt>b.cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long pre=0;
	int n,m,cur;
	cin>>n>>m;
	int arr[200005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		int val=0,num=0;
		cur=arr[i];
		while(cur){
			if(cur%2==1) val++;
			cur/=2,num++;
		}
		arr1[i].cnt=val;
		arr1[i].pos=i;
		arr1[i].nums=num;
	}
	sort(arr1,arr1+n,cmp);
	pre=arr[arr1[0].pos];
	for(int i=1;i<m;i++){
		pre&=arr[arr1[i].pos];
	}
	cout<<pre<<"\n";
	return 0;
}

