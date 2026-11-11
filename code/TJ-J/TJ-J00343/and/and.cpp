#include<bits/stdc++.h>
using namespace std;\
long long m,n,a[1010101],b[1010101],w = 0,sum,cnt;
string s,y,c,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	n--;
	while(m--){
		b[w] = a[n];
		w++;
		n--;
	}
	while(b[0]>0){
		s+=char(b[0]%2+48);
		b[0]/=2;
	}
	for(int i=w;i>=1;i--){
		while(b[i]>0){
			y+=char(b[i]%2+48);
			b[i]/=2;
		}
		int lens = s.size();
		int leny = y.size();
		int d = 0;
		for(int i=leny-1;i>=0;i--){
			x[d] = y[i];
		}
		y = x;
		x = ' ';
		if(lens > leny){
			for(int i=0;i<leny;i++){
				if(int(s[i]-48) && int(y[i]-48)){
					c+='1'; 
				}else{
					c+='0';
				}
			}
			s = c; 
		}else{
			for(int i=0;i<lens;i++){
				if(int(s[i]-48) && int(y[i]-48)){
					c+='1'; 
				}else{
					c+='0'; 
				}
			}
			s = c;
		}
		c = ' ';
	}
	int lenx = s.size();
	for(int i = lenx-1;i >= 0;i++){
		if(s[i] != 0){
			sum += pow(2,cnt);
		}
		cnt++;
	}
	cout << sum;
	return 0;
} 
