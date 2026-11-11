#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int c,t;
int rp(){
	int i=rand();
	int j=rand();
	int k=rand();
	return (((i+j)*k - (j+k)/i + (k-i)^j)+(i+j+k))%(i+j+k);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>c>>t;
	while(t--){
		cout<<rp()<<"\n";// 再见，最后一次csp，祝rp++！ 
	}
	return 0;
}
/*

5:50 试试？
5:57 试个集贸。
注意到 t<=5 ，你说我相不相信运气？

*/
