#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans&=a[i];
	}
	if(m==n){
		cout<<ans;
	}else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==2){
		long long maxn=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[j]&a[i]));
			}
		}
		cout<<maxn;
	}else{
		long long maxn=0;
		if(m==3){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int e=j+1;e<=n;e++){
						maxn=max(maxn,(a[e]&a[j]&a[i]));
					}
				}
			}
		}
		if(m==4){
			for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int e=j+1;e<=n-1;e++){
						for(int c=e+1;c<=n;c++){
							maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]));
						}
					}
				}
			}
		}
		if(m==5){
			for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int e=j+1;e<=n-2;e++){
						for(int c=e+1;c<=n-1;c++){
							for(int c1=c+1;c1<=n;c1++){
								maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]));
							}
						}
					}
				}
			}
		}
		if(m==6){
			for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int e=j+1;e<=n-3;e++){
						for(int c=e+1;c<=n-2;c++){
							for(int c1=c+1;c1<=n-1;c1++){
								for(int c2=c1+1;c2<=n;c2++){
									maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]));
								}
							}
						}
					}
				}
			}
		}
		if(m==7){
			for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int e=j+1;e<=n-4;e++){
						for(int c=e+1;c<=n-3;c++){
							for(int c1=c+1;c1<=n-2;c1++){
								for(int c2=c1+1;c2<=n-1;c2++){
									for(int c3=c2+1;c3<=n;c3++){
										maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]));
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==8){
			for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int e=j+1;e<=n-5;e++){
						for(int c=e+1;c<=n-4;c++){
							for(int c1=c+1;c1<=n-3;c1++){
								for(int c2=c1+1;c2<=n-2;c2++){
									for(int c3=c2+1;c3<=n-1;c3++){
										for(int c4=c3+1;c4<=n;c4++){
											maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==9){
			for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int e=j+1;e<=n-6;e++){
						for(int c=e+1;c<=n-5;c++){
							for(int c1=c+1;c1<=n-4;c1++){
								for(int c2=c1+1;c2<=n-3;c2++){
									for(int c3=c2+1;c3<=n-2;c3++){
										for(int c4=c3+1;c4<=n-1;c4++){
											for(int c5=c4+1;c5<=n;c5++){
												maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]));
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
		if(m==10){
			for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int e=j+1;e<=n-7;e++){
						for(int c=e+1;c<=n-6;c++){
							for(int c1=c+1;c1<=n-5;c1++){
								for(int c2=c1+1;c2<=n-4;c2++){
									for(int c3=c2+1;c3<=n-3;c3++){
										for(int c4=c3+1;c4<=n-2;c4++){
											for(int c5=c4+1;c5<=n-1;c5++){
												for(int c6=c5+1;c6<=n;c6++){
													maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]));
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
		if(m==11){
			for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int e=j+1;e<=n-8;e++){
						for(int c=e+1;c<=n-7;c++){
							for(int c1=c+1;c1<=n-6;c1++){
								for(int c2=c1+1;c2<=n-5;c2++){
									for(int c3=c2+1;c3<=n-4;c3++){
										for(int c4=c3+1;c4<=n-3;c4++){
											for(int c5=c4+1;c5<=n-2;c5++){
												for(int c6=c5+1;c6<=n-1;c6++){
													for(int c7=c6+1;c7<=n;c7++){
														maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]));
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
		if(m==12){
			for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int e=j+1;e<=n-9;e++){
						for(int c=e+1;c<=n-8;c++){
							for(int c1=c+1;c1<=n-7;c1++){
								for(int c2=c1+1;c2<=n-6;c2++){
									for(int c3=c2+1;c3<=n-5;c3++){
										for(int c4=c3+1;c4<=n-4;c4++){
											for(int c5=c4+1;c5<=n-3;c5++){
												for(int c6=c5+1;c6<=n-2;c6++){
													for(int c7=c6+1;c7<=n-1;c7++){
														for(int c8=c7+1;c8<=n;c8++){
															maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]));
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
		if(m==13){
			for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int e=j+1;e<=n-10;e++){
						for(int c=e+1;c<=n-9;c++){
							for(int c1=c+1;c1<=n-8;c1++){
								for(int c2=c1+1;c2<=n-7;c2++){
									for(int c3=c2+1;c3<=n-6;c3++){
										for(int c4=c3+1;c4<=n-5;c4++){
											for(int c5=c4+1;c5<=n-4;c5++){
												for(int c6=c5+1;c6<=n-3;c6++){
													for(int c7=c6+1;c7<=n-2;c7++){
														for(int c8=c7+1;c8<=n-1;c8++){
															for(int c9=c8+1;c9<=n;c9++){
																maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]));
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
		if(m==14){
			for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int e=j+1;e<=n-11;e++){
						for(int c=e+1;c<=n-10;c++){
							for(int c1=c+1;c1<=n-9;c1++){
								for(int c2=c1+1;c2<=n-8;c2++){
									for(int c3=c2+1;c3<=n-7;c3++){
										for(int c4=c3+1;c4<=n-6;c4++){
											for(int c5=c4+1;c5<=n-5;c5++){
												for(int c6=c5+1;c6<=n-4;c6++){
													for(int c7=c6+1;c7<=n-3;c7++){
														for(int c8=c7+1;c8<=n-2;c8++){
															for(int c9=c8+1;c9<=n-1;c9++){
																for(int cc=c9+1;cc<=n;cc++){
																	maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]));
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
		if(m==15){
			for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int e=j+1;e<=n-12;e++){
						for(int c=e+1;c<=n-11;c++){
							for(int c1=c+1;c1<=n-10;c1++){
								for(int c2=c1+1;c2<=n-9;c2++){
									for(int c3=c2+1;c3<=n-8;c3++){
										for(int c4=c3+1;c4<=n-7;c4++){
											for(int c5=c4+1;c5<=n-6;c5++){
												for(int c6=c5+1;c6<=n-5;c6++){
													for(int c7=c6+1;c7<=n-4;c7++){
														for(int c8=c7+1;c8<=n-3;c8++){
															for(int c9=c8+1;c9<=n-2;c9++){
																for(int cc=c9+1;cc<=n-1;cc++){
																	for(int d1=cc+1;d1<=n;d1++){
																		maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]));
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
		if(m==16){
			for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int e=j+1;e<=n-13;e++){
						for(int c=e+1;c<=n-12;c++){
							for(int c1=c+1;c1<=n-11;c1++){
								for(int c2=c1+1;c2<=n-10;c2++){
									for(int c3=c2+1;c3<=n-9;c3++){
										for(int c4=c3+1;c4<=n-8;c4++){
											for(int c5=c4+1;c5<=n-7;c5++){
												for(int c6=c5+1;c6<=n-6;c6++){
													for(int c7=c6+1;c7<=n-5;c7++){
														for(int c8=c7+1;c8<=n-4;c8++){
															for(int c9=c8+1;c9<=n-3;c9++){
																for(int cc=c9+1;cc<=n-2;cc++){
																	for(int d1=cc+1;d1<=n-1;d1++){
																		for(int d2=d1+1;d2<=n;d2++){
																			maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]&a[d2]));
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
		if(m==17){
			for(int i=1;i<=n-16;i++){
				for(int j=i+1;j<=n-15;j++){
					for(int e=j+1;e<=n-14;e++){
						for(int c=e+1;c<=n-13;c++){
							for(int c1=c+1;c1<=n-12;c1++){
								for(int c2=c1+1;c2<=n-11;c2++){
									for(int c3=c2+1;c3<=n-10;c3++){
										for(int c4=c3+1;c4<=n-9;c4++){
											for(int c5=c4+1;c5<=n-8;c5++){
												for(int c6=c5+1;c6<=n-7;c6++){
													for(int c7=c6+1;c7<=n-6;c7++){
														for(int c8=c7+1;c8<=n-5;c8++){
															for(int c9=c8+1;c9<=n-4;c9++){
																for(int cc=c9+1;cc<=n-3;cc++){
																	for(int d1=cc+1;d1<=n-2;d1++){
																		for(int d2=d1+1;d2<=n-1;d2++){
																			for(int d3=d2+1;d3<=n;d3++){
																				maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]&a[d2]&a[d3]));
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
		if(m==18){
			for(int i=1;i<=n-17;i++){
				for(int j=i+1;j<=n-16;j++){
					for(int e=j+1;e<=n-15;e++){
						for(int c=e+1;c<=n-14;c++){
							for(int c1=c+1;c1<=n-13;c1++){
								for(int c2=c1+1;c2<=n-12;c2++){
									for(int c3=c2+1;c3<=n-11;c3++){
										for(int c4=c3+1;c4<=n-10;c4++){
											for(int c5=c4+1;c5<=n-9;c5++){
												for(int c6=c5+1;c6<=n-8;c6++){
													for(int c7=c6+1;c7<=n-7;c7++){
														for(int c8=c7+1;c8<=n-6;c8++){
															for(int c9=c8+1;c9<=n-5;c9++){
																for(int cc=c9+1;cc<=n-4;cc++){
																	for(int d1=cc+1;d1<=n-3;d1++){
																		for(int d2=d1+1;d2<=n-2;d2++){
																			for(int d3=d2+1;d3<=n-1;d3++){
																				for(int d4=d3+1;d4<=n;d4++){
																					maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]&a[d2]&a[d3]&a[d4]));
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
		if(m==19){
			for(int i=1;i<=n-18;i++){
				for(int j=i+1;j<=n-17;j++){
					for(int e=j+1;e<=n-16;e++){
						for(int c=e+1;c<=n-15;c++){
							for(int c1=c+1;c1<=n-14;c1++){
								for(int c2=c1+1;c2<=n-13;c2++){
									for(int c3=c2+1;c3<=n-12;c3++){
										for(int c4=c3+1;c4<=n-11;c4++){
											for(int c5=c4+1;c5<=n-10;c5++){
												for(int c6=c5+1;c6<=n-9;c6++){
													for(int c7=c6+1;c7<=n-8;c7++){
														for(int c8=c7+1;c8<=n-7;c8++){
															for(int c9=c8+1;c9<=n-6;c9++){
																for(int cc=c9+1;cc<=n-5;cc++){
																	for(int d1=cc+1;d1<=n-4;d1++){
																		for(int d2=d1+1;d2<=n-3;d2++){
																			for(int d3=d2+1;d3<=n-2;d3++){
																				for(int d4=d3+1;d4<=n-1;d4++){
																					for(int d5=d4+1;d5<=n;d5++){
																						maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]&a[d2]&a[d3]&a[d4]&a[d5]));
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
		if(m==20){
			for(int i=1;i<=n-19;i++){
				for(int j=i+1;j<=n-18;j++){
					for(int e=j+1;e<=n-17;e++){
						for(int c=e+1;c<=n-16;c++){
							for(int c1=c+1;c1<=n-15;c1++){
								for(int c2=c1+1;c2<=n-14;c2++){
									for(int c3=c2+1;c3<=n-13;c3++){
										for(int c4=c3+1;c4<=n-12;c4++){
											for(int c5=c4+1;c5<=n-11;c5++){
												for(int c6=c5+1;c6<=n-10;c6++){
													for(int c7=c6+1;c7<=n-9;c7++){
														for(int c8=c7+1;c8<=n-8;c8++){
															for(int c9=c8+1;c9<=n-7;c9++){
																for(int cc=c9+1;cc<=n-6;cc++){
																	for(int d1=cc+1;d1<=n-5;d1++){
																		for(int d2=d1+1;d2<=n-4;d2++){
																			for(int d3=d2+1;d3<=n-3;d3++){
																				for(int d4=d3+1;d4<=n-2;d4++){
																					for(int d5=d4+1;d5<=n-1;d5++){
																						for(int d6=d5+1;d6<=n;d6++){
																							maxn=max(maxn,(a[e]&a[j]&a[i]&a[c]&a[c1]&a[c2]&a[c3]&a[c4]&a[c5]&a[c6]&a[c7]&a[c8]&a[c9]&a[cc]&a[d1]&a[d2]&a[d3]&a[d4]&a[d5]&a[d6]));
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
		cout<<maxn;
	}
	return 0;
}
