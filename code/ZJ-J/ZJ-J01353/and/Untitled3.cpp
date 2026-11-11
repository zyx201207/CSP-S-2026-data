#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int q,w,e,p;
	q=3;w=15;
		while(q!=0&&w!=0){
			if(q%2==w%2){
				p+=pow(2,e);
			}
			w=w/2;
			q=q/2;
			e++;
		    }
	cout<<p;
	return 0;
}
