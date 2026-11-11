//xingming:tiehanqing kaohao:SN-J00777 xuexiao:shanxiyananzhongxue
#include<bits/stdc++.h>
using namespace std;
string a[2],b[2];
long long si(string l){
	long long g=l[1]-'0',sh=l[0]-'0';
	return g+10*sh;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	int bo=0;
	if(a[0]==b[0]){
		bo++;
		cout<<1;
		if(si(a[1])==si(b[1])){
			bo++;
			cout<<1;
			if(a[1][2]<'D' and b[1][2]<'D' or a[1][2]>'C' and b[1][2]>'C'){
				bo++;
				cout<<1;
				if(abs(a[1][2]-b[1][2])==1){
					bo++;
					cout<<1;
				}
			}
		}
	}for(int i=0;i < 4-bo;i++){
		cout<<0;
	}return 0;
}
