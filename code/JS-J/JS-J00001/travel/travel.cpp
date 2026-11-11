#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string str;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin,str);

    bool a1=(str[0]==str[7]&&str[1]==str[8]);
	if(a1){
        cout<<'1';
	}
	else cout<<'0';

    bool a2=(str[3]==str[10]&&str[4]==str[11]);
	if(a2&&a1){
        cout<<'1';
	}
	else cout<<'0';

	bool a=(str[5]>'C'),b=(str[12]>'C');
	bool a3=(a==b);
	if(a1&&a2&&a3){
        cout<<'1';
	}
	else cout<<'0';

    bool a4=(-1<=(str[5]-str[12]))&&((str[5]-str[12])<=1);
	if(a1&&a2&&a3&&a4){
        cout<<'1';
	}
	else cout<<'0';

	return 0;
}
