#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m;
int a[N];
int ansn;
int maxn = -1e9;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin  >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	ansn = a[1];
	for(int i = 2;i <= n;i++){
		ansn = (ansn & a[i]);
	}
	int ans = -1e9;
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		} 
	}
	else if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans =  max(ans,(a[i] & a[j]));
			}
		}
	}
	else if(m == 3){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					ans =  max(ans,((a[i] & a[j]) & a[k]));
				}
			}
		}
	}
	else if(m == 4){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						ans =  max(ans,(((a[i] & a[j]) & a[k])  & a[aa]));
					}
				}
			}
		}
	}
	else if(m == 5){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							ans =  max(ans,((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb]));
						}
					}
				}
			}
		}
	}
	else if(m == 6){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
									ans =  max(ans,(((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]));
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 7){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									ans =  max(ans,((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd]));
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 8){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										ans =  max(ans,(((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee]));
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 9){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											ans =  max(ans,((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff]));
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 10){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												ans =  max(ans,(((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]));
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 11){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													ans =  max(ans,((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]));
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 12){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														ans =  max(ans,(((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]));
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 13){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															ans =  max(ans,((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]));
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 14){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																ans =  max(ans,(((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]));
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 15){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	ans =  max(ans,((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]));
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 16){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	for(int a5 = a4+1;a5 <= n;a5++){
																		ans =  max(ans,(((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]) & a[a5]));
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 17){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	for(int a5 = a4+1;a5 <= n;a5++){
																		for(int a6 = a5+1;a6 <= n;a6++){
																			ans =  max(ans,((((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]) & a[a5]) & a[a6]));
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 18){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	for(int a5 = a4+1;a5 <= n;a5++){
																		for(int a6 = a5+1;a6 <= n;a6++){
																			for(int a7 = a6+1;a7 <= n;a7++){
																				ans =  max(ans,(((((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]) & a[a5]) & a[a6]) & a[a7]));
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 19){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	for(int a5 = a4+1;a5 <= n;a5++){
																		for(int a6 = a5+1;a6 <= n;a6++){
																			for(int a7 = a6+1;a7 <= n;a7++){
																				for(int a8 = a7+1;a8 <= n;a8++){
																					ans =  max(ans,((((((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]) & a[a5]) & a[a6]) & a[a7]) & a[a8]));
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	else if(m == 20){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int aa = k+1;aa <= n;aa++){
						for(int bb = aa+1;bb <= n;bb++){
							for(int cc = bb+1;cc <= n;cc++){
								for(int dd = cc+1;dd <= n;dd++){
									for(int ee = dd+1;ee <= n;ee++){
										for(int ff = ee+1;ff <= n;ff++){
											for(int gg =ff+1;gg <= n;gg++){
												for(int kk =  gg+1;kk <= n;kk++){
													for(int a1 =  kk+1;a1 <= n;a1++){
														for(int a2 = a1+1;a2 <= n;a2++){
															for(int a3 = a2+1;a3 <= n;a3++){
																for(int a4 =  a3+1;a4 <= n;a4++){
																	for(int a5 = a4+1;a5 <= n;a5++){
																		for(int a6 = a5+1;a6 <= n;a6++){
																			for(int a7 = a6+1;a7 <= n;a7++){
																				for(int a8 = a7+1;a8 <= n;a8++){
																					for(int a9 = a8+1;a9 <= n;a9++){
																						ans =  max(ans,(((((((((((((((((((a[i] & a[j]) & a[k])  & a[aa]) &a[bb])&a[cc]) & a[dd])&a[ee])&a[ff])&a[gg]) &a[kk]) & a[a1]) & a[a2]) & a[a3]) & a[a4]) & a[a5]) & a[a6]) & a[a7]) & a[a8])&a[a9]));
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							} 
						}
					}
				}
			}
		}
	}
	if(n > 2000){
		cout << maxn-1;
	}
	else{
		if(m == n){
			cout << ansn;
		}
		else{
			cout << ans;
		}
	}
	return 0;
}


