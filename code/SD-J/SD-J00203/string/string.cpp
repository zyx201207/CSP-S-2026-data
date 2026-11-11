#include<bits/stdc++.h>
using namespace std;

struct _set{
	int num;
	char c;
};

vector<_set> str;
long long n,l,r,cnt;

void change(){
	int tmp;
	bool tmpb=str[l].c!=str[r].c;
	if(str[l].num>str[r].num){
		tmp=str[r].num;
		str[l].num-=tmp;
		r--;
	}else if(str[l].num<str[r].num){
		tmp=str[l].num;
		str[r].num-=tmp;
		l++;
	}else if(str[l].num==str[r].num){
		tmp=str[l].num;
		l++;
		r--;
	}
	if(tmpb){
		cnt+=tmp;
	}
	
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=0,r=n-1;
	for(int i=0;i<n;i++){
		_set tmpn;
		cin>>tmpn.num>>tmpn.c;
		str.push_back(tmpn);
	}
	while(l<r) change();
	cout<<cnt;
	return 0;
}
