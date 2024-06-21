add_executable(gametree_test gametree.cpp ../game/game.cpp ${TEST_MAIN_CPP})
add_test(gametree-build_gametree gametree_test --test-case=build_gametree)
add_test(gametree-power2 gametree_test --test-case=is_power_of_two)
