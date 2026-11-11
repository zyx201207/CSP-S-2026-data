#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n = 0;
	cin >> n >> m;
	int crystal[n];
	for(int i = 0;i < n;i ++){
		cin >> crystal[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j ++){
			if(crystal[j] < crystal[i]) swap(crystal[i],crystal[j]);
		}

	}
	int idx = 0; //索引 
	int idx_left = 0,idx_right = 0;
	int delta[n];
	int MAX = crystal[n-1] - crystal[0];
	int ans[MAX];
	int m1 = m;
	for(int aim = crystal[0];aim<=crystal[n-1];aim++){
		idx_left = 0;
		idx_right = 1;
		m1 = m;
		ans[aim] = 0;

		for(int i = 0;i < n;i++){
			delta[i] = max(crystal[i] - aim,aim - crystal[i]); //crystal这个位置和aim的差值 

		}
		
		if(aim >= crystal[idx+1]) idx++;
		//if(aim == crystal[idx+1]) ans[aim]++;

		while(m1 > 0){
			if(delta[idx-idx_left] < delta[idx+idx_right] and idx-idx_left >= 0 and idx != 0){
				m1 -= delta[idx-idx_left];

				idx_left+=1;
			}
			else{
				m1 -= delta[idx+idx_right];

				idx_right+=1;
			}
			if(m1 >= 0) ans[aim] += 1;

		}


	}
	int final_ans = 0; 
	for(int i = 0;i<n;i++){
		if(final_ans < ans[i]) final_ans = ans[i];
	}
	cout << final_ans;
	return 0;
}
