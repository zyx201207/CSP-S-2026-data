#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n,m,a[maxn],ans;
int i[2000];
int main()                                                                                                                
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >>a[i];
	}
	if(m>=1){
		for(i[1] = 1;i[1]<=n;i[1]++){
			if(m>=2){
				for(i[2] = 1;i[2]<=n;i[2]++)
				{
					if(i[1] == i[2]) break;
					if(m>=3){
						for(i[3] = 1;i[3]<=n;i[3]++){
							if(i[2] == i[3]) break;
							if(m>=4){
								for(i[4] = 1;i[4]<=n;i[4]++){
									if(i[3] == i[4]) break;
									if(m>=5){
										for(i[5] = 1;i[5]<=n;i[5]++)
										{
											if(i[4] == i[5]) break;
											if(m>=6)
											{
												for(i[6] = 1;i[6]<=n;i[6]++)
												{
													if(i[5] == i[6]) break;
													if(m>=7){
														for(i[7] = 1;i[7] <= n;i[7]++)
														{
															if(i[6] == i[7]) break;
															if(m>=8)
															{
																for(i[8] = 1;i[8] <= n;i[8]++)
																{
																	if(i[7] == i[8]) break;
																	if((a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]] & a[i[7]] & a[i[8]]) >= ans)
																	{
																		ans = (a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]] & a[i[7]] & a[i[8]]);
																	}
																}
															}
															else if((a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]] & a[i[7]]) >= ans)
															{
																ans = (a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]] & a[i[7]]);
															}
														}
													}
													else if((a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]]) >= ans)
													{
														ans = (a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]] & a[i[6]]);
													}
												}
											}
											else if((a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]]) >= ans)
											{
												ans = (a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]] & a[i[5]]);
											}
										}
									}
									else if((a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]]) >= ans){
										ans = (a[i[1]] & a[i[2]] & a[i[3]] & a[i[4]]);
									}
								}
							}
							else if((a[i[1]] & a[i[2]] & a[i[3]]) >= ans)
							{
								ans = (a[i[1]] & a[i[2]] & a[i[3]]);
							}
						}
					}
					else if((a[i[1]] & a[i[2]]) >= ans)
					{
						ans = (a[i[1]] & a[i[2]]);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
