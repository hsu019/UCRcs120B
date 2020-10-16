# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'This test will run first.',
    'steps': [ {'inputs': [('PINA',0x60),('PINB',0x02),('PINC',0x21)], 'iterations': 1 } ],
    'expected': [('PORTD',0x80)],
    },
    {'description': 'This test will run second.',
    'steps': [ 
        {'inputs': [('PINA',0x30),('PINB',0x30),('PINC',0x30)], 'iterations': 1}, ],
    'expected': [('PORTD',0x91)],
    },
    {'description': 'This is test will run third.',
    'steps': [ {'inputs': [('PINA',0x90),('PINB',0x08),('PINC',0x0B)], 'iterations': 1 } ],
    'expected': [('PORTD',0xA3)],
    },
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['main::tmpA,tmpB,tmpC','PORTD']
