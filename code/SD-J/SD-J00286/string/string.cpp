#include <bits/stdc++.h>
using namespace std;
int n,ll = 1,rr;
long long al,ar,num = 0;
char sl,sr;
void ifif(int l,int r){
	if(l>=r)
	if(ll != l){
		ll = l;
		cin >> al >> sl;
	}if(rr != r){
		rr = r;
		cin >> ar >> sr;
	}
	if(sl == sr){
		if(al >= ar){
			al -= ar;
			r--;
			if(al == 0){
				l++;
			}
			ifif(l,r);
		}else{
			ar-=al;
			l++;
			ifif(l,r);
		}
	}else{
		if(al >= ar){
			num += ar;
			al -= ar;
			r--;
			if(al == 0){
				l++;
			}
			ifif(l,r);
		}else{
			num+-al;
			ar-=al;
			l++;
			ifif(l,r);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	rr = n;
	cin >> al >> sl >> ar >> sr;
	ifif(1,n);
	cout << num;
	return 0;
}
