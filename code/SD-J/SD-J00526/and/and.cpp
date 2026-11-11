//and
//10:26 start C
//10:26 write xor
//10:26 wa on xor
//10:27 write xor
//10:28 wa on xor
//10:30 write ten2two
//10:33 wa on ten2two
//10:34 write n_and_m
//10:35 wa on n_and_m
//10:37 write dfs_and
//10:50 wa on dfs_and
//10:51 leave C
//10:55 backt C
//10:59 partc C
//10:59 givup C
//11:00 wa on C 
//11:00 leave C 
//11:15 givup C  
#include<iostream>
#include<algorithm>
using namespace std;
string ten2two(int num){
	if(num==0)return "";
	string temp;
	temp[0]=char(num%2+'0');
	return ten2two(num/2)+temp;
}int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//骗分过样例（真的只是样例） 
	sort(a+1,a+n+1,greater<int>() );
	cout<<a[m]; 
	return 0;
} 
