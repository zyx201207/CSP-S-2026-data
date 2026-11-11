#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char y;
};
long long ans, ml, mid;
node s[200005];
int n, flag;
stack<node> st;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin  >>  n;
	for(int i = 1;i <= n;++i){
		node j;
		cin  >>  j.x  >>  j.y;
		s[i] = j;
		ml += j.x;
	}
	if(ml % 2 != 0){
		flag = 1;
	}
	mid = ml / 2;
	int i = 1;
	for(long long j = 0;j < mid;){
		if(j + s[i].x > mid){
			node k;
			k.x = mid - j;k.y = s[i].y;
			s[i].x -= k.x;
			st.push(k);
			break;
		}
		st.push(s[i]);
		j += s[i].x;
		i++;
	}
	if(flag){
		s[i].x--;
	}
	while(!st.empty()){
		node j = st.top();
		st.pop();
		if(j.y == s[i].y){
			if(j.x < s[i].x){
				s[i].x -= j.x;
			}else if(j.x == s[i].x){
				i++;
			}else{
				j.x -= s[i].x;
				st.push(j);
				i++;
			}
		}else{
			if(j.x < s[i].x){
				ans += j.x;
				s[i].x -= j.x;
			}else if(j.x == s[i].x){
				ans += j.x;
				i++;
			}else{
				ans += s[i].x;
				j.x -= s[i].x;
				st.push(j);
				i++;
			}
		}
	}
	cout  <<  ans;
	return 0;
}
